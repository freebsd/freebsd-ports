#!/bin/sh

tr -d '\r' < $1 > $1_
mv -f $1_ $1
