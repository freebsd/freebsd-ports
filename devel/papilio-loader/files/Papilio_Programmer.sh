#!/bin/sh

if [ -z "$1" -o -z "$2" -o \! -f "$2" ]; then
  echo "Usage: $0 -t|-p bitfile"
  echo "-t : Program FPGA - Temporary"
  echo "-p : Program SPI Flash - Permanent"
  exit 0
fi

datadir="%%DATADIR%%"

case "$1" in
  "-t")
	echo "Programming the FPGA"
  	papilio-prog -v -f $2 -v
  	exit 0
  	;;
  "-p")
	echo "Programming to SPI Flash"
	devid=`papilio-prog -j | awk '{print $9}'`
	echo "$devid"
	case "$devid" in
	XC3S250E)
		echo "Programming a Papilio One 250K"
		bscan_bitfile=bscan_spi_xc3s250e.bit
		;;
	XC3S500E)
		echo "Programming a Papilio One 500K"
		bscan_bitfile=bscan_spi_xc3s500e.bit
		;;
	XC6SLX9)
		echo "Programming a Papilio Plus LX9"
		bscan_bitfile=bscan_spi_xc6slx9.bit
		;;
	*)
		echo "Unknown Papilio Board"
		exit 1
		;;
	esac
	papilio-prog -v -f "$2" -b "$datadir/$bscan_bitfile" -sa -r;
	papilio-prog -c
esac

