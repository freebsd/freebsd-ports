# New ports collection makefile for:	njs
# Date created:		Fri Jan 11 20:45:26 GMT 2002
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	njs
PORTVERSION=	0.2.5
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.bbassett.net/pub/njs/	\
		http://www.bbassett.net/njs/	\
		http://www.iki.fi/mtr/js/
DISTNAME=	js-${PORTVERSION}

MAINTAINER=	thierry@pompo.net

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
MAKE_ARG=	MAKEINFO="makeinfo --no-split"

MAN1=	js.1 jsdas.1

post-extract:
	${RM} ${WRKSRC}/docs/js.info*

post-patch:
	${PERL} -pi -e 's:=makeinfo:="makeinfo --no-split":g' ${WRKSRC}/configure

pre-install:
.if defined(NOPORTDOCS)
	${PERL} -pi -e "s:docs micros examples:micros:g" ${WRKSRC}/Makefile
.endif

post-install:
.if !defined(NOPORTDOCS)
.for info in js.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"
	@${ECHO_MSG}

.include <bsd.port.mk>
