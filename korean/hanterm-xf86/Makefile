# New ports collection makefile for:	hanterm-xf86-v32
# Version required:     xf86-v32
# Date created:		22 Mar 1997
# Whom:			Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.1.1.1 1997/04/18 08:45:48 asami Exp $
#

DISTNAME=       hanterm-xf86-v32
PKGNAME=	ko-hanterm-xf86-3.2
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/incoming/ \
		ftp://jazz.snu.ac.kr/pub/unix/util/X11/
EXTRACT_SUFX=   .tgz

RUN_DEPENDS=    ${PREFIX}/lib/X11/fonts/korean/johab:$(PORTSDIR)/korean/johabfonts

MAINTAINER=	junker@jazz.snu.ac.kr

USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

# rename app-defaults files
post-extract:
	@cd ${WRKSRC}; \
	mv XTerm.ad Hanterm.ad; \
	mv XTerm-col.ad Hanterm-col.ad

.include <bsd.port.mk>
