# New ports collection makefile for:	MHonArc
# Date created:			17 March 1999
# Whom:				Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	mhonarc
PORTVERSION=	2.3.3
CATEGORIES=	japanese www
MASTER_SITES=	http://www.oac.uci.edu/indiv/ehood/tar/ \
		ftp://hhobel.phl.univie.ac.at/MHonArc/ \
		ftp://contrib.redhat.com/noarch/ \
		ftp://ftp.plig.org/pub/CPAN/authors/id/EHOOD/ \
		http://www.perl.com/CPAN/authors/id/EHOOD/ \
		http://www.shiratori.riec.tohoku.ac.jp/~p-katoh/Hack/Docs/mhonarc-jp/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flathill
DISTNAME=	MHonArc${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		iso2022.pl
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	flathill@FreeBSD.org

Y2K=		http://www.oac.uci.edu/indiv/ehood/MHonArc/doc/faq/general.html#y2k

USE_PERL5=	Yes
NO_BUILD=	Yes

.include <bsd.port.pre.mk>

pre-install:
	${CP} ${DISTDIR}/iso2022.pl ${WRKSRC}/lib/

do-install:
	cd ${WRKSRC} && ${PERL5} install.me -prefix ${PREFIX} -batch
	${MKDIR} ${PREFIX}/share/examples/MHonArc
	${INSTALL_DATA} ${FILESDIR}/mhonarc.rc.sample ${PREFIX}/share/examples/MHonArc/

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
