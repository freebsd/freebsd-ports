PORTNAME=	pdfkit
PORTVERSION=	0.8.7.3
CATEGORIES=	graphics rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Uses wkhtmltopdf to create PDFs using HTML
WWW=		https://github.com/pdfkit/pdfkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired converters/wkhtmltopdf
EXPIRATION_DATE=2025-03-31

RUN_DEPENDS=	wkhtmltopdf:converters/wkhtmltopdf

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project

NO_ARCH=	yes

.include <bsd.port.mk>
