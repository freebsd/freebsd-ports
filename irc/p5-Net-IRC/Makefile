# New ports collection makefile for:	p5-Net-IRC
# Date created:				2001-03-02
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		Net-IRC
PORTVERSION=		0.70
CATEGORIES=		irc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=		p5-

MAINTAINER=		trevor@FreeBSD.org

DOCS=			TODO Changes README
DOCDIR=			share/doc/p5-Net-IRC
MAN3=			Net::IRC.3 Net::Connection.3 Net::DCC.3 Net::Event.3
MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
PLIST=			${WRKDIR}/pkg-plist
PERL_CONFIGURE=		yes

pre-install:
	${ECHO} share/examples/p5-Net-IRC/irctest > ${PLIST}
.for i in Net/IRC.pm Net/IRC/Connection.pm Net/IRC/Event.pm Net/IRC/DCC.pm
	${ECHO} lib/perl5/site_perl/%%PERL_VER%%/${i} >>${PLIST}
.endfor
	${ECHO} lib/perl5/site_perl/%%PERL_VER%%/%%PERL_ARCH%%/auto/Net/IRC/.packlist >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO} ${DOCDIR}/${i} >> ${PLIST}
.endfor
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif
	${ECHO} @dirrm lib/perl5/site_perl/%%PERL_VER%%/Net/IRC >> ${PLIST}
	${ECHO} @dirrm lib/perl5/site_perl/%%PERL_VER%%/Net >> ${PLIST}
	${ECHO} @dirrm lib/perl5/site_perl/%%PERL_VER%%/%%PERL_ARCH%%/auto/Net \
		>> ${PLIST}
	${ECHO} @dirrm share/examples/p5-Net-IRC >> ${PLIST}

post-install:
	${MKDIR} ${PREFIX}/share/examples/p5-Net-IRC
	${INSTALL_SCRIPT} ${WRKSRC}/irctest ${PREFIX}/share/examples/p5-Net-IRC
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/p5-Net-IRC
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/p5-Net-IRC/
.endfor
.endif

.include <bsd.port.mk>
