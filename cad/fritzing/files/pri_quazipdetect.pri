message("Using FreeBSD-provided quazip detect script.")

SOURCES += \
        src/zlibdummy.c \

INCLUDEPATH += "%%LOCALBASE%%/include/QuaZip-Qt6-1.5/"
LIBS += "-lquazip1-qt6"
