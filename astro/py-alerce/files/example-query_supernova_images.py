#!/usr/bin/env python3
"""
Example script demonstrating how to use the ALeRCE Python client
to query supernova images from the Vera C. Rubin Observatory (LSST).

ALeRCE (Automatic Learning for the Rapid Classification of Events) 
processes alerts from the Rubin Observatory and provides easy access
to astronomical object data, lightcurves, and image stamps.
"""

from alerce.core import Alerce
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


def query_supernova_data(oid, survey="lsst"):
    """
    Query supernova data including lightcurve and image stamps.
    
    Parameters:
    -----------
    oid : str
        Object ID for the supernova candidate
    survey : str
        Survey name (default: "lsst" for Rubin Observatory)
    
    Returns:
    --------
    tuple: (lightcurve_data, stamps_data)
    """
    # Initialize the ALeRCE client
    client = Alerce()
    
    print(f"Querying object: {oid}")
    print(f"Survey: {survey}")
    print("-" * 50)
    
    # Get lightcurve data
    try:
        lightcurve = client.query_lightcurve(oid=oid, survey=survey, format="pandas")
        print(f"✓ Retrieved lightcurve with {len(lightcurve)} detections")
    except Exception as e:
        print(f"✗ Error retrieving lightcurve: {e}")
        lightcurve = None
    
    # Get image stamps (cutouts)
    try:
        stamps = client.get_stamps(oid=oid, survey=survey)
        print(f"✓ Retrieved image stamps")
    except Exception as e:
        print(f"✗ Error retrieving stamps: {e}")
        stamps = None
    
    return lightcurve, stamps


def display_stamps(stamps):
    """
    Display science, reference, and difference image stamps.
    
    Parameters:
    -----------
    stamps : dict
        Stamp data from ALeRCE (FITS HDU objects)
    """
    if not stamps:
        print("No stamps available to display")
        return
    
    print("\nProcessing image stamps...")
    
    fig, axes = plt.subplots(1, 3, figsize=(15, 5))
    
    # Map stamp names to plot titles
    stamp_mappings = [
        (['cutoutScience', 'science'], 'Science Image'),
        (['cutoutTemplate', 'template', 'reference'], 'Reference Template'),
        (['cutoutDifference', 'difference', 'diff'], 'Difference Image')
    ]
    
    for ax, (possible_names, title) in zip(axes, stamp_mappings):
        image_found = False
        
        try:
            # Try to find the stamp with various possible names
            stamp_data = None
            used_name = None
            for name in possible_names:
                if name in stamps:
                    stamp_data = stamps[name]
                    used_name = name
                    break
            
            if stamp_data is not None:
                # Check if it's an Astropy FITS HDU object
                if hasattr(stamp_data, 'data'):
                    # Extract the image data from FITS HDU
                    image_array = stamp_data.data
                    
                    if image_array is not None and image_array.size > 0:
                        # Normalize for better display
                        vmin = np.percentile(image_array, 1)
                        vmax = np.percentile(image_array, 99)
                        
                        im = ax.imshow(image_array, cmap='gray', origin='lower', 
                                      vmin=vmin, vmax=vmax)
                        ax.set_title(title)
                        ax.axis('off')
                        image_found = True
                        print(f"  ✓ Displayed {title} (shape: {image_array.shape})")
                    else:
                        print(f"  ✗ {title}: Empty data array")
                else:
                    print(f"  ✗ {title}: Not a FITS HDU object (type: {type(stamp_data)})")
        
        except Exception as e:
            print(f"  ✗ Error loading {title}: {str(e)}")
        
        if not image_found:
            ax.text(0.5, 0.5, f'{title}\nNot Available', 
                   ha='center', va='center', transform=ax.transAxes,
                   fontsize=12)
            ax.axis('off')
    
    plt.tight_layout()
    plt.savefig('supernova_stamps.png', dpi=150, bbox_inches='tight')
    print("\n✓ Saved image stamps to: supernova_stamps.png")
    plt.show()


def plot_lightcurve(lightcurve):
    """
    Plot the supernova lightcurve.
    
    Parameters:
    -----------
    lightcurve : pandas.DataFrame or dict
        Lightcurve data from ALeRCE
    """
    if lightcurve is None:
        print("No lightcurve data available to plot")
        return
    
    # Handle nested structure - extract detections
    if isinstance(lightcurve, dict):
        if 'detections' in lightcurve:
            detections = lightcurve['detections']
            if isinstance(detections, pd.DataFrame):
                lightcurve = detections
            else:
                print("Detections data is not a DataFrame")
                return
        else:
            print("No 'detections' key found in lightcurve data")
            return
    
    if len(lightcurve) == 0:
        print("No detections in lightcurve data")
        return
    
    plt.figure(figsize=(12, 6))
    
    # Determine column names (they may vary between surveys)
    filter_col = None
    for col in ['fid', 'filter', 'band', 'filtername']:
        if col in lightcurve.columns:
            filter_col = col
            break
    
    mag_col = None
    for col in ['magpsf', 'mag', 'magnitude']:
        if col in lightcurve.columns:
            mag_col = col
            break
    
    magerr_col = None
    for col in ['sigmapsf', 'e_mag', 'magerr', 'mag_err']:
        if col in lightcurve.columns:
            magerr_col = col
            break
    
    time_col = None
    for col in ['mjd', 'time', 'jd']:
        if col in lightcurve.columns:
            time_col = col
            break
    
    if not mag_col or not time_col:
        print(f"Error: Could not find required columns. Available columns: {list(lightcurve.columns)}")
        return
    
    # Group by filter/band if available
    if filter_col:
        for fid in lightcurve[filter_col].unique():
            band_data = lightcurve[lightcurve[filter_col] == fid]
            if magerr_col:
                plt.errorbar(band_data[time_col], band_data[mag_col], 
                            yerr=band_data[magerr_col],
                            fmt='o', label=f'Filter {fid}', alpha=0.7, markersize=8)
            else:
                plt.plot(band_data[time_col], band_data[mag_col], 
                        'o', label=f'Filter {fid}', alpha=0.7, markersize=8)
    else:
        # No filter information, plot all data together
        if magerr_col:
            plt.errorbar(lightcurve[time_col], lightcurve[mag_col], 
                        yerr=lightcurve[magerr_col],
                        fmt='o', alpha=0.7, markersize=8)
        else:
            plt.plot(lightcurve[time_col], lightcurve[mag_col], 'o', alpha=0.7, markersize=8)
    
    plt.xlabel('Modified Julian Date (MJD)' if time_col == 'mjd' else 'Time', fontsize=12)
    plt.ylabel('Magnitude', fontsize=12)
    plt.gca().invert_yaxis()  # Invert y-axis (brighter objects have lower magnitude)
    plt.title('Supernova Lightcurve', fontsize=14)
    if filter_col:
        plt.legend()
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig('supernova_lightcurve.png', dpi=150, bbox_inches='tight')
    print("✓ Saved lightcurve to: supernova_lightcurve.png")
    plt.show()


def main():
    """
    Main function to demonstrate querying supernova data from Rubin Observatory.
    """
    print("=" * 60)
    print("ALeRCE Supernova Query Example")
    print("Vera C. Rubin Observatory / LSST")
    print("=" * 60)
    print()
    
    # Example Rubin LSST supernova candidate object ID
    # Note: Replace with a valid LSST object ID from the ALeRCE database
    # You can find object IDs at: https://science.alerce.online/alerce-lsst/
    example_oid = "170032901203689551"
    
    print("NOTE: This example uses a placeholder object ID.")
    print("For real data, obtain valid LSST object IDs from:")
    print("  - ALeRCE Explorer: https://science.alerce.online/alerce-lsst/")
    print("  - Or query the ALeRCE API for classified supernovae")
    print()
    
    # Query the data
    lightcurve, stamps = query_supernova_data(example_oid, survey="lsst")
    
    print()
    
    # Display results
    if lightcurve is not None:
        print("\nLightcurve Summary:")
        
        # Handle nested structure
        detections = None
        if isinstance(lightcurve, dict):
            if 'detections' in lightcurve:
                detections = lightcurve['detections']
                if isinstance(detections, pd.DataFrame):
                    print(f"  - Number of detections: {len(detections)}")
                    print(f"  - Available columns: {list(detections.columns)}")
                    
                    # Check for time column
                    time_col = None
                    for col in ['mjd', 'time', 'jd']:
                        if col in detections.columns:
                            time_col = col
                            break
                    
                    if time_col:
                        print(f"  - Time range: {detections[time_col].min():.2f} to {detections[time_col].max():.2f}")
                    
                    # Check for filter column
                    filter_col = None
                    for col in ['fid', 'filter', 'band', 'filtername']:
                        if col in detections.columns:
                            filter_col = col
                            break
                    
                    if filter_col:
                        print(f"  - Filters: {detections[filter_col].unique()}")
        
        # Plot lightcurve
        plot_lightcurve(lightcurve)
    
    if stamps is not None:
        print("\nImage Stamps:")
        num_stamps = len(stamps) if isinstance(stamps, list) else 1
        print(f"  - Retrieved {num_stamps} stamp(s)")
        
        # Display stamps
        display_stamps(stamps)
    else:
        print("\n⚠ No image stamps were retrieved")
        print("  This may be because:")
        print("  - The object ID doesn't exist in the database")
        print("  - Image stamps are not available for this object")
        print("  - The survey parameter may need adjustment")
    
    print()
    print("=" * 60)
    print("Query complete!")
    print("=" * 60)


if __name__ == "__main__":
    main()
