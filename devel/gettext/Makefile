# New ports collection makefile for:   gettext
# Version required:    0.10
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.3 1998/09/23 17:58:38 vanilla Exp $
#

DISTNAME=	gettext-0.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	Nakai@technologist.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnu-gettext

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

post-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	@install-info ${PREFIX}/info/gettext.info ${PREFIX}/info/dir

.include <bsd.port.mk>
