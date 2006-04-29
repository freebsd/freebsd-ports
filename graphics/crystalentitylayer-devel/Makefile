# New ports collection makefile for:	Crystal Entity Layer
# Date created:		2005-10-02
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	crystalentitylayer
PORTVERSION=	0.99
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cel
DISTNAME=	cel-pseudo-stable-2006-01-27

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	CEL is a layer that sits on top of Crystal Space 3D Engine

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam \
		cs-config:${PORTSDIR}/graphics/crystalspace

USE_X_PREFIX=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_ARGS+=	--with-cs-prefix=${X11BASE}
MAKE_ENV=	CC="${CC}" CFLAGS="${CFLAGS} ${CXX}" LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
DOCSDIR?=	share/doc/cel-${PORTVERSION}
DATADIR?=	share/cel
PLIST_SUB+=	DOCSDIR=${DOCSDIR} \
		DATADIR=${DATADIR}
WRKSRC=	${WRKDIR}/cel

OPTIONS=	DEBUG	"Build with debugging information"	off \
		PYTHON	"Python Behaviour Layer"	on \
		CPPUNIT	"The C++ Unit Test Library"	on \
		BFD	"Universal BFD library from the GNU binutils"	on

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 504000
BROKEN=		Does not build on FreeBSD >= 5.x
.endif

.if!defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=yes
.else
CONFIGURE_ARGS+=	--enable-debug=no
.endif

.if!defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
.include <${PORTSDIR}/Mk/bsd.python.mk>
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if!defined(WITHOUT_CPPUNIT)
LIB_DEPENDS+=	cppunit-1.10:${PORTSDIR}/devel/cppunit
.else
CONFIGURE_ARGS+=	--without-cppunit
.endif

.if!defined(WITHOUT_BFD)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libbfd.a:${PORTSDIR}/devel/libbfd
.else
CONFIGURE_ARGS+=	--without-bfd
.endif

post-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 61d ${WRKSRC}/Jamfile
.endif

do-build:
	@cd ${WRKSRC} && jam -q

do-install:
	@cd ${WRKSRC} && jam install

.include <bsd.port.post.mk>
