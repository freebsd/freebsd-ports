# ex:ts=8
# New ports collection makefile for:	snack
# Date created:			Nov 24, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	snack
PORTVERSION=	2.1.4
CATEGORIES=	audio tcl83 tk83
MASTER_SITES=	http://www.speech.kth.se/~kare/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${LOCALBASE}/lib/tcl8.3 \
		--with-tk=${LOCALBASE}/lib/tk8.3
PLIST_SUB=	SNACK_VER=${PORTVERSION:R}

post-patch:
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
