# Created by: msmith@gsoft.com.au
# $FreeBSD$

PORTNAME=	bwbasic
PORTVERSION=	2.60
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/version%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Bywater Basic interpreter

NO_WRKSUBDIR=	yes

USES=		dos2unix zip
GNU_CONFIGURE=	yes
MAKE_ARGS=	CFLAGS="${CFLAGS} -ansi"
ALL_TARGET=	${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
post-patch:
	@${CHMOD} a+x ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.doc ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/bwbtest; ${COPYTREE_SHARE} . ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
