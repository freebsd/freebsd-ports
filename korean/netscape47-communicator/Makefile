# New ports collection makefile for:	netscape-intl-ko
# Version required:     3.01intl/ko
# Date created:		6 Apr 1995
# Whom:			Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.3 1997/09/22 16:22:08 max Exp $
#

DISTNAME=	netscape-3.01
PKGNAME=	ko-netscape-3.01intl
CATEGORIES=	korean www
MASTER_SITES=	ftp://archive.netscape.com/archive/navigator/3.01/unix/\
		ftp://archive.netscape.com/archive/navigator/intl/3.01/unix/ko/
DISTFILES=	netscape-v301-export.x86-unknown-bsd.tar.gz netscape-ko-v301.alpha-dec-osf2.0.tar.gz

MAINTAINER=	junker@jazz.snu.ac.kr

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/korean/hanyang:$(PORTSDIR)/korean/hanyangfonts

RESTRICTED=	"Commercial software"
NO_WRKSUBDIR=	yes

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
