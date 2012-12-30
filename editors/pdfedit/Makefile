# New ports collection makefile for:	pdfedit
# Date created:				2007-12-20
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	pdfedit
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free editor for manipulating PDF documents (QT3 GUI and CLI)

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	boost_filesystem.4:${PORTSDIR}/devel/boost-libs \
		t1.5:${PORTSDIR}/devel/t1lib

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/LICENSE.GPL

USE_BZIP2=	yes
USE_QT_VER=	3
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QMAKESPEC="${LOCALBASE}/share/qt/mkspecs/freebsd-g++"
CONFIGURE_ARGS=	--with-t1-library=${LOCALBASE}/lib \
		--with-t1-includes=${LOCALBASE}/include \
		--with-parallel-make=off
MAKE_ENV=	${CONFIGURE_ENV}
MAKE_JOBS_SAFE=	yes

MAN1=		pdfedit.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pedantic||g ; \
		 s| $$(OPTIM)||g ; \
		 s| $$(ARCH)||g ; \
		 s| -pipe.*$$||g ; \
		 s|^CFLAGS =|CFLAGS +=|g ; \
		 s|^CXXFLAGS =|CXXFLAGS +=|g' ${WRKSRC}/Makefile.flags.in
	@${REINPLACE_CMD} -e \
		'/QMAKE/s| make| $$MAKE|g' ${WRKSRC}/src/qsa/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in Changelog README doc/AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
