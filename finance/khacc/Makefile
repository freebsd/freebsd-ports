# New ports collection makefile for:	khacc
# Date created:		22 Jan 2003
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	khacc
PORTVERSION=	1.7.7
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qhacc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple KDE-base financial manager

LIB_DEPENDS=	qhacc.3:${PORTSDIR}/finance/qhacc
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_KDELIBS_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-qhacc-config=${X11BASE}/bin
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CXXFLAGS+=	-fpermissive
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/khacc/khacc.in
	@${REINPLACE_CMD} -e 's|-pedantic||g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
