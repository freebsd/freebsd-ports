# New ports collection makefile for:	hanterm3.04
# Version required:     3.04beta7
# Date created:		12 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.5 1998/10/16 02:03:00 jseger Exp $
#

DISTNAME=	hanterm304beta7
PKGNAME=	ko-hanterm-3.04b7
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/incoming/hantermbeta7/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/terminal/hanterm/hanterm304beta/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/terminal/hanterm/hanterm304beta/

MAINTAINER=	junker@jazz.snu.ac.kr

RUN_DEPENDS=	${PREFIX}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

.include <bsd.port.mk>
