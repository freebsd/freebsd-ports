# New ports collection makefile for:	XEmacs additional packages except for mule
# Date created:		14 Feb 2000
# Whom:			KIRIYAMA Kazuhiko<kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xemacs-additional-packages
PORTVERSION=	1.0
CATEGORIES=	editors
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	kiri@pis.toba-cmt.ac.jp

RUN_DEPENDS=	${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.zenirc:${PORTSDIR}/editors/xemacs-comm-packages \
		${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.misc-games:${PORTSDIR}/editors/xemacs-games-packages \
		${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.tooltalk:${PORTSDIR}/editors/xemacs-libs-packages \
		${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.calc:${PORTSDIR}/editors/xemacs-oa-packages \
		${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.vhdl:${PORTSDIR}/editors/xemacs-prog-packages \
		${LOCALBASE}/lib/xemacs/xemacs-packages/pkginfo/MANIFEST.tpu:${PORTSDIR}/editors/xemacs-wp-packages

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/doc/xemacs-additional-packages

post-install:
	@${ECHO_MSG} "    This is the additional package for XEmacs(version over 21). You can install"
	@${ECHO_MSG} "all packages except for basic(xemacs-packages), basic mule(xemacs-basic-mule)"
	@${ECHO_MSG} "and mule(xemacs-mule-packages). You can also install \`sumo'-like packages with"
	@${ECHO_MSG} "xemacs-packages and xemacs-additional-packages. If you think install individual"
	@${ECHO_MSG} "package, try to use other xemacs-*-packages. These packages are prepared for"
	@${ECHO_MSG} "installation by xemacs categories."
	@${ECHO_MSG} "    You can also install with running it as root and using the 'Manage Packes'"
	@${ECHO_MSG} "menu within the 'Options' menu of the menubar. But using this xemacs package"
	@${ECHO_MSG} "managing, you could not be control under ports managing ;-)"

.include <bsd.port.mk>
