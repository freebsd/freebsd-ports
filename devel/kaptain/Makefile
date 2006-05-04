# ex:ts=8
#
# New ports collection makefile for:	kaptain
# Date created:			2002-12-12
# Whom:				Alan Eldridge <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kaptain
PORTVERSION=	0.72
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for building/running QT GUIs for commmand line programs

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-mt \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

MAN1=		kaptain.1
INFO=		kaptain

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/examples/dia2code.kaptn

.include <bsd.port.mk>
