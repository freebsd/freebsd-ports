# $FreeBSD$

PORTNAME=	cvs
PORTVERSION=	1.20120905
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	LOCAL/eadler

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Version control system

LICENSE=	GPLv2

OPTIONS_DEFINE=		KERBEROS
OPTIONS_DEFAULT=	KERBEROS

USES=		makeinfo tar:xz uidfix
WRKSRC=		${WRKDIR}/call/cvs-build
INFO=		cvs cvsclient

# bsd.stage.makes sets the wrong value for DESTDIR
DESTDIRNAME=	NADA
MAKE_ARGS=	DESTDIR=${STAGEDIR}${PREFIX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKERBEROS}
MAKE_ARGS+=	KERBEROS_SUPPORT=yes
.else
MAKE_ARGS+=	KERBEROS_SUPPORT=no
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900000
BROKEN=	does not link
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/contrib

.include <bsd.port.post.mk>
