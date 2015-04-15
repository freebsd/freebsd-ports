# $FreeBSD$

PORTNAME=	cvs
PORTVERSION=	1.20120905
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	LOCAL/eadler

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Version control system

LICENSE=	GPLv2 # or any later version

OPTIONS_DEFINE=	KERBEROS EXAMPLES
OPTIONS_DEFAULT=KERBEROS

KERBEROS_MAKE_ARGS=	KERBEROS_SUPPORT=yes

USES=		makeinfo tar:xz uidfix
WRKSRC=		${WRKDIR}/call/cvs-build
INFO=		cvs cvsclient

# bsd.stage.makes sets the wrong value for DESTDIR
DESTDIRNAME=	NADA
MAKE_ARGS=	DESTDIR=${STAGEDIR}${PREFIX}

pre-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/contrib

.include <bsd.port.mk>
