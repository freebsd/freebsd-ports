# New ports collection makefile for:   gettext
# Version required:    0.10.35
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.7 1999/03/08 07:28:22 asami Exp $
#

DISTNAME=	gettext-0.10.35
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.ai.mit.edu/gnu/ \
		ftp://alpha.gnu.org/pub/gnu

MAINTAINER=	nacai@iname.com

GNU_CONFIGURE=	yes

PLIST_SUB=	X11BASE=${X11BASE}

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/gettext.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${WRKSRC}/misc/po-mode.el \
		${PREFIX}/share/gettext/po-mode.el
	${MKDIR} ${X11BASE}/share/locale

.include <bsd.port.mk>
