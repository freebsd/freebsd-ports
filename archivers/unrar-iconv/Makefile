# Created by: Yarodin <yarodin@gmail.com>
# $FreeBSD$

PKGNAMESUFFIX=	-iconv

MAINTAINER=	yarodin@gmail.com

MASTERDIR=	${.CURDIR}/../unrar

EXTRA_PATCHES=	${.CURDIR}/files/patch-iconv

CPPFLAGS+=	-DWITH_ICONV -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
USES=		iconv

CONFLICTS_INSTALL=	unrar

post-install:
	@${ECHO_MSG} "===> Added iconv support, see new switches:"
	@${ECHO_MSG} "     la, ll and lo at \"unrar -?\""
	@${ECHO_MSG} "===> REMEMBER!!!: Windows rar archives using old DOS encodings as internal encoding."
	@${ECHO_MSG} "     CP866 for russian lang for example."

.include "${MASTERDIR}/Makefile"
