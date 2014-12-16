# $FreeBSD$

PORTNAME=	libxo
PORTVERSION=	0.1.6
CATEGORIES=	devel textproc
MASTER_SITES=	http://github.com/Juniper/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Library to generate text, XML, JSON, and HTML output

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright

USES=		gmake libtool perl5
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_PERL5=	run

.include <bsd.port.mk>
