# New ports collection makefile for:   gettext
# Version required:    0.10.35
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.5 1998/12/01 22:38:45 billf Exp $
#

DISTNAME=	gettext-0.10.35
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.ai.mit.edu/gnu/

MAINTAINER=	nacai@iname.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-gnu-gettext

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/gettext.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${WRKSRC}/misc/po-mode.el \
		${PREFIX}/share/gettext/po-mode.el

.include <bsd.port.mk>
