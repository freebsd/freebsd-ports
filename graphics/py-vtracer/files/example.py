import urllib.request
import vtracer

# 1. Define file paths and download target
url = "https://forums.freebsd.org/attachments/image_widget_w0nk11mh60i71-png.14467/index.png"
input_path = "bsd-logo.png"
output_path = "bsd-logo.svg"

print("Downloading the PNG image...")
urllib.request.urlretrieve(url, input_path)

# 2. Convert the downloaded image to SVG
print("Converting image to SVG...")
vtracer.convert_image_to_svg_py(input_path, output_path)

print(f"Successfully saved vector graphic to {output_path}!")
