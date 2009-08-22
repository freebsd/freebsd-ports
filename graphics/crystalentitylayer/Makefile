# New ports collection makefile for:	Crystal Entity Layer
# Date created:		2005-10-02
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	crystalentitylayer
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/cel/cel/${PORTVERSION}
DISTNAME=	cel-src-${PORTVERSION}
DIST_SUBDIR=	crystalspace

MAINTAINER=	acm@FreeBSD.org
COMMENT=	CEL is a layer that sits on top of Crystal Space 3D Engine

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam \
		cs-config:${PORTSDIR}/graphics/crystalspace

CONFLICTS=	crystalentitylayer-devel-[0-9]*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

LDFLAGS=	-L${LOCALBASE}/lib
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-cs-prefix=${LOCALBASE}
MAKE_ENV=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
DOCSDIR=	share/doc/cel-${PORTVERSION}
DATADIR=	share/cel
PLIST_SUB+=	DOCSDIR=${DOCSDIR} \
		DATADIR=${DATADIR}

JAM_CMD=	${LOCALBASE}/bin/jam
JAM_ARGS=	-qa

OPTIONS=	DEBUG	"Build with debugging information"	off \
		PYTHON	"Python Behaviour Layer"	on \
		CPPUNIT	"The C++ Unit Test Library"	on \
		BFD	"Universal BFD library from the GNU binutils"	on

.include <bsd.port.pre.mk>

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug=no
.else
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

.if!defined(WITHOUT_PYTHON)
USE_PYTHON=	-2.4
.include <${PORTSDIR}/Mk/bsd.python.mk>
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if!defined(WITHOUT_CPPUNIT)
BUILD_DEPENDS+=	cppunit-config:${PORTSDIR}/devel/cppunit
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
	@${REINPLACE_CMD} -e 63d ${WRKSRC}/Jamfile
.endif

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${JAM_CMD} ${JAM_ARGS}

do-install:
	@cd ${WRKSRC} && \
		${JAM_CMD} install

.include <bsd.port.post.mk>
