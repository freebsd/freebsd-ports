# Created by: Konstantin Reznichenko <kot@premierbank.dp.ua>
# $FreeBSD$

PORTNAME=	arj
PORTVERSION=	3.10.22
PORTREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.78_3.10%20build%2022

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Open source implementation of the ARJ archiver

LICENSE=	GPLv2

PORTSCOUT=	skipv:3.10g

USES=		alias gmake
USE_AUTOTOOLS=	autoconf
CONFIGURE_WRKSRC=	${WRKSRC}/gnu
MAKEFILE=	GNUmakefile
MAKE_ARGS=	LOCALE="${LANGUAGE}"
ALL_TARGET=	prepare all
STRIP=		# empty
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-fPIC
LANGUAGE?=	en

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's!/etc!${LOCALBASE}/etc!' \
		 ${WRKSRC}/arj.c ${WRKSRC}/file_reg.c ${WRKSRC}/rearj.c
	@${REINPLACE_CMD} -e 's!-O2!!' ${WRKSRC}/gnu/configure.in
	@${REINPLACE_CMD} -e 's!^static !!' ${WRKSRC}/integr.c

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} COPYING debug.txt \
		${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/resource/en && ${INSTALL_DATA} arjl.txt arjs.txt \
		history.txt readme.txt unix.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
