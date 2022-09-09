PKGNAMESUFFIX=	-slang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slang interface for TiMidity++
WWW=		http://timidity.sourceforge.net/

CONFLICTS_INSTALL=	ja-timidity++-slang # lib/timidity/if_slang.so

MASTERDIR=	${.CURDIR}/../../audio/timidity++

PLIST_FILES=	${TIMID_LIBDIR}/if_${INTERFACE}.so

.include "${MASTERDIR}/Makefile"
