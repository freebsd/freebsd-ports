# New ports collection makefile for:	zh-auto-tw-l10n
# Date created:		7 Oct 2000
# Whom:			"Michael C . Wu" <keichii@iteration.net>
#
# $FreeBSD$

PORTNAME=	auto-tw-l10n
PORTVERSION=	1.2
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.iteration.net/pub/patch_chinese/
DISTNAME=	zh-tw-skel-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	keichii@freebsd.org

NO_BUILD=	yes

do-install:
#Temporary hack before adduser is modified
#	For future adduser
#	adduser -l10n -v $HOME
	${MKDIR} ${PREFIX}/share/skel/zh_TW.Big5
	${CP} ${WRKDIR}/zh_TW.Big5/* ${PREFIX}/share/skel/zh_TW.Big5
	@${ECHO} "*************************************************************"
	@${ECHO} "* English Instructions:                                     *"
	@${ECHO} "* Please tell your users to merge their old dotfiles with   *"
	@${ECHO} "* the new ones, in                                          *"
	@${ECHO} "* ${PREFIX}/share/skel/zh_TW.Big5/dot.*                    *"
	@${ECHO} "*************************************************************"
	@${ECHO} "* 中文大五碼說明:                                           *"
	@${ECHO} "* 請告知您的使用者比對他們的舊設定跟新設定, 在              *"
	@${ECHO} "* ${PREFIX}/share/skel/zh_TW.Big5/dot.*                     *"
	@${ECHO} "*************************************************************"

.include <bsd.port.mk>
