# $FreeBSD$

PORTNAME=	dnsenum
PORTVERSION=	1.2.4.2
CATEGORIES=	dns

MAINTAINER=	rihaz.jerrin@gmail.com
COMMENT=	Enumerate DNS information and discover non-contiguous IP blocks

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-IP>=0:net-mgmt/p5-Net-IP \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask \
		p5-Net-Whois>=0:net/p5-Net-Whois \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-XML-Writer>=0:textproc/p5-XML-Writer \
		p5-String-Random>=0:devel/p5-String-Random

USE_GITHUB=	yes
GH_ACCOUNT=	fwaeytens

USES=		perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/dnsenum.pl

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/dnsenum \
		${DOCSDIR_REL}/README \
		${DOCSDIR_REL}/INSTALL.txt \
		${DATADIR_REL}/dns.txt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dnsenum.pl ${STAGEDIR}${PREFIX}/bin/dnsenum
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/INSTALL.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dns.txt ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
