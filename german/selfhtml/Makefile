# Created by: Frerich Raabe <frerich.raabe@gmx.de>
# $FreeBSD$

PORTNAME=	selfhtml
PORTVERSION=	8.1.2
PORTEPOCH=	1
CATEGORIES=	german www
MASTER_SITES=	http://aktuell.de.selfhtml.org/extras/ \
		http://ftp.join.uni-muenster.de/pub/documents/selfhtml/ \
		ftp://ftp.uni-ulm.de/mirrors/selfhtml/ \
		http://free.w3research.com/ \
		http://selfhtml.hegglin.net/ \
		http://www.meta-text.net/ \
		http://www.lichteinfall.de/ \
		http://www.mastko.de/ \
		http://www.a-mazing.de/downloads/ \
		http://download.iansview.com/mirror/selfhtml.org/ \
		ftp://ftp.rub.de/pub/selfhtml/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensive German HTML reference

NO_ARCH=	yes
NO_BUILD=	yes
USES=		dos2unix zip
EXTRACT_AFTER_ARGS= -d ${WRKSRC}
DOS2UNIX_REGEX=	.*\.(css|dhtml|diverses|editorial|grafik|helferlein|htm|inter|intro|javascript|layouts|navigation|perl|php|projekt|quellen|servercgi|src|xml|xls|dtd)$$

PORTDOCS=	index.htm \
		css \
		dhtml \
		diverses \
		editorial \
		grafik \
		helferlein \
		html \
		inter \
		intro \
		javascript \
		layouts \
		navigation \
		perl \
		php \
		projekt \
		quellen \
		servercgi \
		src \
		xml

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
