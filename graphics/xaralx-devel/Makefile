# New ports collection makefile for:	XaraLX development version
# Date created:				12 Apr 2006
# Whom:					Vasil Dimov <vd@FreeBSD.org>
#
# $FreeBSD$
#

PORTVERSION=	0.5r1184
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz

COMMENT=	Top-tier vector/general purpose graphics program (development version)

BUILD_DEPENDS=	xml2-config:${PORTSDIR}/textproc/libxml2

MASTERDIR=	${.CURDIR}/../xaralx
MD5_FILE=	${.CURDIR}/distinfo

PATCHDIR=	${.CURDIR}/files
EXTRA_PATCHES=	${MASTERDIR}/files/patch-PreComp_Makefile.am

# we're using dlmalloc because the stock libc does not have malloc_usable_size()
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -ldlmalloc"

# add wxOil with -I- appended to it before any other -I stuff, see below
MAKE_ENV=	INCLUDES="-I../wxOil -I- -I${LOCALBASE}/include/dlmalloc" \

# we need to strip wxOil from the include path because it contains file
# named strings.h which when included by /usr/include/string.h results
# in a complete mess
post-patch:
	${REINPLACE_CMD} -E -e 's|-I[^[:space:]]*/wxOil[[:space:]]||g' \
		${WRKSRC}/Makefile.am

.include "${MASTERDIR}/Makefile"
