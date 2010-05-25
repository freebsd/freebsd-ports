# New ports collection makefile for:	asterisk-sounds-jp
# Date created:				27 June 2007
# Whom:		Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	asterisk
PORTVERSION=	1.4
PORTREVISION=	7
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.voip-info.jp/asterisk/sounds/${PORTVERSION:S|.|_|}/ \
		http://ftp.voip-info.jp/asterisk/sounds/${PORTVERSION:S|.|_|}/
PKGNAMESUFFIX=	-sounds
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX:S|s$||}-jp_${PORTVERSION:S|.||}_beta

MAINTAINER=	jfkimura@yahoo.co.jp
COMMENT=	Japanese sound files for Asterisk

RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

NO_BUILD=	yes
ASTERISKDIR=	${DATADIR}/${PKGNAMESUFFIX:S|-||}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

post-extract:
	${MV} ${WRKDIR}/jp/README.txt ${WRKDIR}

do-install:
	@-${MKDIR} ${ASTERISKDIR}
	@${CP} -pR ${WRKDIR}/jp ${ASTERISKDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/ja
	@cd ${WRKDIR} && ${INSTALL_DATA} README.txt ${DOCSDIR}/ja
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	@${FIND} ${ASTERISKDIR}/jp -type f -o -type l | ${SORT} | ${SED} -e 's,^${PREFIX}/,,' > pkg-plist.new
	@${FIND} ${ASTERISKDIR}/jp -type d -depth | ${SORT} -r | ${SED} -e 's,^${PREFIX}/,@dirrm ,' >> pkg-plist.new
	@${ECHO} %%PORTDOCS%%%%DOCSDIR%%/ja/README.txt >> pkg-plist.new
	@${ECHO} %%PORTDOCS%%@dirrm %%DOCSDIR%%/ja >> pkg-plist.new
	@${ECHO} %%PORTDOCS%%@dirrm %%DOCSDIR%% >> pkg-plist.new

.include <bsd.port.mk>
