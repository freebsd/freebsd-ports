# New ports collection makefile for:	selfhtml
# Date created:			January 7th 2005
# Whom:				Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	selfhtml
PORTVERSION=	80
PORTREVISION=	1
CATEGORIES=	german www
MASTER_SITES=	http://www.fsai.fh-trier.de/~gielj/files/ \
		http://home.t-online.de/home/b.michna/selfhtml/ \
		http://dj5nu.bei.t-online.de/ \
		http://www.mtory.de/selfhtml/ \
		http://www.unet.univie.ac.at/~a9105535/ \
		http://www.jonasstein.de/mirror/ \
		http://home.t-online.de/home/AundG.Hofmann/selfhtml/ \
		http://selfhtml.occuris.de/download/ \
		http://studwww.ira.uka.de/~s_buerk/selfhtml/ \
		http://www.stud.uni-goettingen.de/software/ \
		http://www.meta-text.net/
PKGNAMEPREFIX=	de-
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	frerich.raabe@gmx.de
COMMENT=	Extensive german HTML reference

USE_REINPLACE=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	\
		index.htm \
		cgiperl \
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
		php \
		projekt \
		quellen \
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
