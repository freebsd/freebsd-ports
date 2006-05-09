# Ports collection Makefile for:  mozilla-flp
# Date created:			  Sat Nov 01, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	mozilla-flp
PORTVERSION=	1.7.13
CATEGORIES=	french www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}	\
		http://frenchmozilla.sourceforge.net/FTP/${PORTVERSION}/
MASTER_SITE_SUBDIR=	frenchmozilla
DISTNAME=	mozilla-${PORTVERSION}.fr-FR.langpack

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Mozilla French Language Pack (FLP)

USE_X_PREFIX=	yes	# Cannot be included after <bsd.port.pre.mk>.
WRKSRC=		${WRKDIR}/bin

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

REPS=		defaults/profile/FR/chrome defaults/messenger/FR defaults/isp/FR
FICHIERS=	chrome/FR.jar chrome/fr-FR.jar chrome/fr-unix.jar			\
		components/myspell/fr-FR.aff components/myspell/fr-FR.dic		\
		defaults/isp/FR/movemail.rdf defaults/messenger/FR/mailViews.dat	\
		defaults/profile/FR/bookmarks.html					\
		defaults/profile/FR/chrome/userChrome-example.css			\
		defaults/profile/FR/chrome/userContent-example.css			\
		defaults/profile/FR/localstore.rdf defaults/profile/FR/mimeTypes.rdf	\
		defaults/profile/FR/panels.rdf defaults/profile/FR/search.rdf		\
		searchplugins/jeeves.gif searchplugins/jeeves.src searchplugins/dmoz.gif\
		searchplugins/dmoz.src searchplugins/google.gif searchplugins/google.src\
		searchplugins/googlefr.gif searchplugins/googlefr.src

do-install:
.for rep in ${REPS}
	@${MKDIR} ${MOZDIR}/${rep}
.endfor
.for fichier in ${FICHIERS}
	@${INSTALL_DATA} ${WRKSRC}/${fichier} ${MOZDIR}/`dirname ${fichier}`
.endfor

.include <bsd.port.post.mk>
