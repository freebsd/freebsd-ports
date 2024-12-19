PORTNAME=	split-sequence
PORTVERSION=	20011114.1
PORTREVISION=	3
CATEGORIES=	devel lisp
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Partitioning Common Lisp sequences
WWW=		https://www.cliki.net/SPLIT-SEQUENCE

LICENSE=	PD

USES=		cl

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	@${INSTALL_DATA} ${WRKSRC}/split-sequence.lisp ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/split-sequence.asd ${STAGEDIR}${ASDF_PATHNAME}
	@${RLN} ${STAGEDIR}${ASDF_PATHNAME}/split-sequence.asd ${STAGEDIR}${ASDF_REGISTRY}

.include <bsd.port.mk>
