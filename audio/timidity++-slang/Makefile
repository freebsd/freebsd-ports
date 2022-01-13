# Created by: Yoichi Asai <yatt@msc.biglobe.ne.jp>

PKGNAMESUFFIX=	-slang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slang interface for TiMidity++

CONFLICTS_INSTALL=	ja-timidity++-slang # lib/timidity/if_slang.so

MASTERDIR=	${.CURDIR}/../../audio/timidity++

PLIST_FILES=	${TIMID_LIBDIR}/if_${INTERFACE}.so

.include "${MASTERDIR}/Makefile"
