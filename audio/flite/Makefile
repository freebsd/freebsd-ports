# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flite
PORTVERSION=	1.4
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/flite/packed/${PORTNAME}-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-release

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A small run-time speech synthesis engine

USES=		gmake
NO_STAGE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

CFLAGS:=	${CFLAGS:N-O:N-O[0123456789]} -O0

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-pd|-p|g' ${WRKSRC}/main/Makefile

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
