#!/bin/sh 
DIA_LIB_PATH=$DIA_LIB_PATH:%%PREFIX%%/lib/dia
DIA_SHAPE_PATH=%%PREFIX%%/share/gnome/dia/shapes
DIA_SHEET_PATH=%%PREFIX%%/share/gnome/dia/sheets
export DIA_LIB_PATH DIA_SHAPE_PATH DIA_INT_SHAPE_PATH DIA_SHEET_PATH

exec %%PREFIX%%/bin/dia-bin "$@"
