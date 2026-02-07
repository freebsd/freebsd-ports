PORTNAME=	infix
PORTVERSION=	19960628
PORTREVISION=	4
CATEGORIES=	devel lisp
MASTER_SITES=	http://ftp.linux.org.uk/pub/lisp/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://thingamy.com/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
DISTNAME=	${PORTNAME}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Lisp macro for reading math expressions in infix form
WWW=		https://www.cliki.net/infix

# Converted from NO_CDROM
LICENSE=	infix
LICENSE_NAME=	infix
LICENSE_TEXT=	No fees or compensation can be charged
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		cl

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/infix.cl ${WRKSRC}/infix.lisp

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/infix.asd ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/infix.system ${STAGEDIR}${ASDF_PATHNAME}
	@${RLN} ${STAGEDIR}${ASDF_PATHNAME}/infix.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in COPYING infix.3lisp
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
