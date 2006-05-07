# New ports collection makefile for:	gnome-verbiste
# Date created:				29 November 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	fr-gnome-

COMMENT=	French verb conjugator/deconjugator (GNOME program and applet)

LIB_DEPENDS=	verbiste-0.1:${PORTSDIR}/french/verbiste

USE_X_PREFIX=	yes
USE_GNOME=	gnomepanel
CONFIGURE_ARGS=	--with-gnome

MASTERDIR=	${.CURDIR}/../verbiste

EXTRA_PATCHES=	${.CURDIR}/files/patch-*
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/ s|po||; /^SUBDIRS =/ s|examples||' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^SUBDIRS =/ s|verbiste commands||' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|^localedir = .*|localedir = ${LOCALBASE}/share/locale|' \
		${WRKSRC}/src/gnome/Makefile.in
	@${REINPLACE_CMD} -e 's|\.\./verbiste/libverbiste-$$(API)\.la|-lverbiste-$$(API)|; \
		/^libdatadir =/ s|$$(datadir)|${LOCALBASE}/share|' \
		${WRKSRC}/src/gui/Makefile.in ${WRKSRC}/src/gnome/Makefile.in

.include "${MASTERDIR}/Makefile"
