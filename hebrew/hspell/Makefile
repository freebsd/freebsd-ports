# Ports collection makefile for:  hspell
# Date created:			  03 Feb 2003
# Whom:				  Yonatan <Yonatan@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	hspell
PORTVERSION=	0.5
CATEGORIES=	hebrew
MASTER_SITES=	http://www.ivrix.org.il/projects/spell-checker/

MAINTAINER=	yonatan@xpert.com
COMMENT=	Hebrew spellchecker and morphology engine

USE_PERL5=	yes

MAN1=		hspell.1

.if defined(NO_VERBOSE)
ALL_TARGET=install_compressed
PLIST_SUB+=	NOVERB=""
PLIST_SUB+=	VERB="@comment "
.else
PLIST_SUB+=	NOVERB="@comment "
PLIST_SUB+=	VERB=""

pre-everything::
	@${ECHO_CMD} "If you want a smaller, faster version where the -v"
	@${ECHO_CMD} "option is dysfunctional, stop now and use NO_VERBOSE."
	@sleep 3
.endif

post-install:
	@${SED} -e "s:%%PORTSDIR%%:${PORTSDIR}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
