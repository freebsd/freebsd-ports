# Created by: ijliao
# $FreeBSD$

PORTNAME=	regina
PORTVERSION=	3.7
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-rexx/${PORTNAME}-rexx/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	Regina-REXX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Rexx interpreter

CONFLICTS=	rexx-imc-* oorexx-[0-9]*

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
USE_RC_SUBR=	rxstack

MAN1=	regina.1 regina-config.1 rxqueue.1 rxstack.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e "s|-xchar=unsigned||g" ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not link on powerpc
.endif

.include <bsd.port.post.mk>
