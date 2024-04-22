PORTNAME=	atlc
PORTVERSION=	4.6.1
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to calculate the impedance of transmission lines
WWW=		https://atlc.sourceforge.net/

LICENSE=	GPLv2+

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		tar:bzip2
GNU_CONFIGURE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

MAKE_ARGS=	examplesdir=${EXAMPLESDIR} \
		htmldir=${DOCSDIR}/html-docs \
		jpgdir=${DOCSDIR}/html-docs/jpgs \
		qexdir=${DOCSDIR}/qex-december-1996 \
		mandir=${PREFIX}/share/man

.include <bsd.port.mk>
