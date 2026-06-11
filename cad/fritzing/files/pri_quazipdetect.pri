message("Using FreeBSD-provided quazip detect script.")

SOURCES += \
        src/zlibdummy.c \

INCLUDEPATH += $$system(pkgconf --cflags-only-I quazip1-qt6|sed 's,-I,,g')
LIBS += "-lquazip1-qt6"
