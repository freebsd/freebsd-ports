# ex:ts=8
# Ports collection makefile for:	flowdesigner
# Date created:			Apr 14, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flowdesigner
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	FlowDesigner-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free (GPL) "data flow oriented" development environment

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

USE_GCC=	3.4
USE_GNOME=	gnomehack gnometarget libgnomeui libxml2
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fftw-includes=${LOCALBASE}/include \
		--with-fftw-libraries=${LOCALBASE}/lib
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.if ${OSVERSION} < 500035
CFLAGS+=	-O0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|tools examples|tools|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|src pixmaps|src|g' ${WRKSRC}/vflow/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.n ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.wav ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
