PORTNAME=	splint
DISTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	devel security
MASTER_SITES=	http://www.splint.org/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Tool for statically checking sourcecode for security vulnerabilities
WWW=		https://www.splint.org/

LICENSE=	GPLv2+

USES=		gmake tar:tgz

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	BISON=no

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/Headers/constants.h
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		 ${REINPLACE_CMD} -e '/^pkgdatadir =/s|=.*|=${DATADIR}|'

.include <bsd.port.mk>
