# New ports collection makefile for:	selfhtml
# Date created:			January 7th 2005
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

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

WRKSRC=		${WRKDIR}

USE_ZIP=	yes
NO_BUILD=	yes

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(css|dhtml|diverses|editorial|grafik|helferlein|htm|inter|intro|javascript|layouts|navigation|perl|php|projekt|quellen|servercgi|src|xml|xls|dtd)$$

PORTDOCS=	\
		index.htm \
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
	@${MKDIR} ${DOCSDIR}
# line taken from textproc/xerces-j maintained by hq@FreeBSD.org
# recursively create dirs and install docs
	@cd ${WRKSRC} && \
		${FIND} ${PORTDOCS} -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} ${PORTDOCS} -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;

.include <bsd.port.mk>
