# New ports collection makefile for:    gshar+gunshar
# Version required:     4.2
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.12 1998/01/23 00:43:26 jseger Exp $
#

DISTNAME=       sharutils-4.2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	sharutils

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --program-prefix=g --disable-uucode
INSTALL_TARGET= install install-man
MAN1=		gshar.1 gunshar.1

post-patch:
	@touch ${WRKSRC}/po/sharutils.pot

post-install:
.for file in gshar gunshar
	strip ${PREFIX}/bin/${file}
.endfor
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in remsync.info sharutils.info
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
