#!/bin/sh
# This script checks for the existence of the three very important Z88
# parameter files z88.fcd, z88.dyn and z88i4.txt and launches the
# Z88 commander
# This file was taken from the Z88 RPM distribution

if ! test -f z88.dyn
  then
    cp %%PREFIX%%/share/z88/z88.dyn .
fi

if ! test -f z88.fcd
  then
    cp %%PREFIX%%/share/z88/z88.fcd .
fi

if ! test -f z88i4.txt
  then
    cp %%PREFIX%%/share/z88/b1_4.txt z88i4.txt
fi

if ! test -f z88i1.txt
  then
    if ! test -f z88ni.txt
      then
        if ! test -f z88x.dxf
          then
            if ! test -f z88g.cos
              then
                cp %%PREFIX%%/share/z88/b1_x.dxf z88x.dxf
                cp %%PREFIX%%/share/z88/b1_2.txt z88i2.txt
                cp %%PREFIX%%/share/z88/b1_3.txt z88i3.txt
                echo "First Z88 example loaded"
              else
                echo "A Z88 input file z88g.cos exists"
            fi
          else
            echo "A Z88 input file z88x.dxf exists"
        fi
      else
        echo "A Z88 input file z88ni.txt exists"
    fi
  else
    echo "A Z88 input file z88i1.txt exists"
fi

echo "For further information consult"
echo "http://www.z88.org/ or "
echo "%%PREFIX%%/share/doc/z88/z88mane.pdf (English)"
echo "*** Starting the Z88 Finite Elements Analysis system ***"

z88com &
