# New ports collection makefile for:	selfhtml
# Date created:			January 7th 2005
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	selfhtml
PORTVERSION=	81
CATEGORIES=	german www
MASTER_SITES=	http://ftp.join.uni-muenster.de/pub/documents/selfhtml/ \
		ftp://ftp.uni-ulm.de/mirrors/selfhtml/ \
		http://free.w3research.com/ \
		http://selfhtml.hegglin.net/ \
		http://www.meta-text.net/ \
		http://www.lichteinfall.de/ \
		http://www.mastko.de/ \
		http://www.a-mazing.de/downloads/ \
		http://download.iansview.com/mirror/selfhtml.org/ \
		ftp://ftp.rub.de/pub/selfhtml/
PKGNAMEPREFIX=	de-
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	frerich.raabe@gmx.de
COMMENT=	Extensive german HTML reference

USE_ZIP=	yes
NO_BUILD=	yes

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

post-patch:
# \r\n -> \n on text files
	@${FIND} -E ${WRKSRC} \
		-iregex \
		".*\.(css|ent|htm|java|js|txt|url|vcf|wrl|xhtml|xml)$$" \
		-type f -print0 \
		| ${XARGS} -0 -n 5 -x \
			${REINPLACE_CMD} -E \
			-e 's|||'
# remove extraneous backup files
	@${FIND} ${WRKSRC} -type f -name "*.bak" -print0 \
		| ${XARGS} -0 -n 5 -x \
			${RM} -f

do-install:
	@${MKDIR} ${DOCSDIR}
# line taken from textproc/xerces-j maintained by hq@FreeBSD.org
# recursively create dirs and install docs
	@cd ${WRKSRC} && \
		${FIND} ${PORTDOCS} -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} ${PORTDOCS} -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;

.include <bsd.port.mk>
