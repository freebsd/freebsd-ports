# New ports collection makefile for:	med
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	med
PORTVERSION=	2.2.3
PORTREVISION=	2
CATEGORIES=	french cad converters
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}_fichier${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modélisation et Échanges de Données

BUILD_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}
LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5
RUN_DEPENDS=	wish${TK_VER}:${PORTSDIR}/x11-toolkits/tk${SHORT_TK_VER}

TK_VER?=	8.4
SHORT_TK_VER=	${TK_VER:S/.//}

#CONFIGURE_ARGS=	--disable-shared
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	HDF5HOME=${LOCALBASE} CPPFLAGS="${PTHREAD_CFLAGS}"	\
		LDFLAGS="${PTHREAD_LIBS}" WISH=${LOCALBASE}/bin/wish${TK_VER}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

DOC2FIX=	. gif html jpg png tests
TST2FIX=	c f

.include <bsd.port.pre.mk>

.if !${OSVERSION} < 500039
F77?=		f77
.endif
FFLAGS?=	-O2

pre-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|SUBDIRS = src tests tools doc|SUBDIRS = src tests tools|'	\
		${WRKSRC}/Makefile.in
.endif
.for dd in ${DOC2FIX}
	@${REINPLACE_CMD} -e 's|docdir = $$(datadir)/doc|docdir = $$(datadir)/doc/@PACKAGE@|'	\
		${WRKSRC}/doc/${dd}/Makefile.in
.endfor
.for dd in ${TST2FIX}
	@${REINPLACE_CMD} -e 's|test${dd}dir = $$(bindir)/test|test${dd}dir = ${EXAMPLESDIR}/test|' \
		${WRKSRC}/tests/${dd}/Makefile.in
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
