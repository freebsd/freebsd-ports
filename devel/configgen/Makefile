# New ports collection makefile for:	configgen
# Date created:		2005-09-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	configgen
PORTVERSION=	1.15
CATEGORIES=	devel
MASTER_SITES=	http://www.marcuscom.com:8080/cgi-bin/cvsweb.cgi/portstools/
DISTNAME=	${PORTNAME}.sh?rev=${PORTVERSION}
EXTRACT_SUFX=	# empty

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Script that makes life a little easier with gnu-autotools

PLIST_FILES=	bin/${PORTNAME}.sh
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GNUTOOLS)
.for tool in autoconf213 autoconf253 autoconf259 automake14 automake15 automake19
RUN_DEPENDS+=	${tool}:${PORTSDIR}/devel/${tool}
.endfor
RUN_DEPENDS+=	libtool:${PORTSDIR}/devel/libtool15
.for tool in autoconf automake libtool
RUN_DEPENDS+=	${LOCALBASE}/gnu-autotools/bin/${tool}:${PORTSDIR}/devel/gnu-${tool}
.endfor
RUN_DEPENDS+=	gnome-autogen.sh:${PORTSDIR}/devel/gnomecommon
.endif

pre-everything::
.if !defined(WITHOUT_GNUTOOLS)
	@${ECHO_MSG} "You can disable the dependency of gnu-autotools by"
	@${ECHO_MSG} "defining WITHOUT_GNUTOOLS=yes"
	@${ECHO_MSG} ""
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	${SED} -e 's|/usr/local|${LOCALBASE}|g; s|/usr/X11R6|${X11BASE}|g' \
		< ${DISTDIR}/${DISTNAME} > ${WRKSRC}/${PORTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh ${PREFIX}/bin

.include <bsd.port.post.mk>
