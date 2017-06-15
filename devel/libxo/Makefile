# $FreeBSD$

PORTNAME=	libxo
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	https://github.com/Juniper/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Library to generate text, XML, JSON, and HTML output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright

USES=		autoreconf gmake libtool pathfix perl5
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_PERL5=	run

.include <bsd.port.mk>
