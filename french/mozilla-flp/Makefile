# Ports collection Makefile for:  mozilla-flp
# Date created:			  Sat Nov 01, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	${GECKO}-flp
PORTVERSION=	${MOZVERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	french www
MASTER_SITES=	SF/frenchmozilla/French%20SeaMonkey/${PORTVERSION}	\
		http://frenchmozilla.sourceforge.net/FTP/${PORTVERSION}${DISTURL}/

DISTNAME=	${GECKO}-${PORTVERSION}.fr-FR.langpack

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	${GECKO} French Language Pack (FLP)

WRKSRC=		${WRKDIR}/bin

REPS=		defaults/profile/FR/chrome defaults/messenger/FR defaults/isp/FR	\
		components/myspell
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

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozex/Makefile.xpi"

.if ${GECKO} == mozilla
MOZVERSION=	1.7.13
DISTURL=	# No subdir
FICHIERS+=	defaults/isp/FR/gmail.rdf
PLIST_SUB+=	MOZ=""
.else
MOZVERSION=	1.1.17
DISTURL=	/SeaMonkey
MD5_FILE=	${MASTERDIR}/distinfo.seamonkey
PLIST_SUB+=	MOZ="@comment "
.endif

do-install:
.for rep in ${REPS}
	@${MKDIR} ${MOZDIR}/${rep}
.endfor
.for fichier in ${FICHIERS}
	@${INSTALL_DATA} ${WRKSRC}/${fichier} ${MOZDIR}/`dirname ${fichier}`
.endfor

.include <bsd.port.post.mk>
