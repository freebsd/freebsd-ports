# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PORTNAME=	svk
PORTVERSION=	2.2.3
PORTREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CLKAO
DISTNAME=	SVK-v${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Distributed Version Control System

BUILD_DEPENDS=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-subversion>=0:${PORTSDIR}/devel/p5-subversion \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Algorithm-Annotate>=0:${PORTSDIR}/devel/p5-Algorithm-Annotate \
		p5-App-CLI>=0:${PORTSDIR}/devel/p5-App-CLI \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-Data-Inheritable>=0:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-FreezeThaw>=0:${PORTSDIR}/devel/p5-FreezeThaw \
		p5-IO-Digest>=0:${PORTSDIR}/devel/p5-IO-Digest \
		p5-IO-Pager>=0:${PORTSDIR}/devel/p5-IO-Pager \
		p5-Log-Log4perl>=0:${PORTSDIR}/devel/p5-Log-Log4perl \
		p5-Pod-Escapes>=0:${PORTSDIR}/textproc/p5-Pod-Escapes \
		p5-Pod-Simple>=0:${PORTSDIR}/textproc/p5-Pod-Simple \
		p5-Regexp-Shellish>=0:${PORTSDIR}/devel/p5-Regexp-Shellish \
		p5-SVN-Mirror>=0:${PORTSDIR}/devel/p5-SVN-Mirror \
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Algorithm-Diff>=1.1901:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Class-Autouse>=1.15:${PORTSDIR}/devel/p5-Class-Autouse \
		p5-Data-Hierarchy>=0.30:${PORTSDIR}/devel/p5-Data-Hierarchy \
		p5-Locale-Maketext-Lexicon>=0.62:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Locale-Maketext-Simple>=0.16:${PORTSDIR}/devel/p5-Locale-Maketext-Simple \
		p5-Path-Class>=0.16:${PORTSDIR}/devel/p5-Path-Class \
		p5-PerlIO-eol>=0.13:${PORTSDIR}/devel/p5-PerlIO-eol \
		p5-PerlIO-gzip>=0.18:${PORTSDIR}/archivers/p5-PerlIO-gzip \
		p5-PerlIO-via-Bzip2>=0.02:${PORTSDIR}/archivers/p5-PerlIO-via-Bzip2 \
		p5-PerlIO-via-dynamic>=0.11:${PORTSDIR}/devel/p5-PerlIO-via-dynamic \
		p5-PerlIO-via-symlink>=0.02:${PORTSDIR}/devel/p5-PerlIO-via-symlink \
		p5-SVN-Dump>=0.04:${PORTSDIR}/devel/p5-SVN-Dump \
		p5-SVN-Simple>=0.27:${PORTSDIR}/devel/p5-SVN-Simple \
		p5-SVN-Mirror>=0.71:${PORTSDIR}/devel/p5-SVN-Mirror \
		p5-Time-Progress>=0:${PORTSDIR}/devel/p5-Time-Progress \
		p5-YAML-Syck>=0.60:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-version>=0.68:${PORTSDIR}/devel/p5-version
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO} ""
	@${ECHO} "If you see some missing dependency, please update your"
	@${ECHO} "ports tree and upgrade it with 'portupgrade -R svk'."
	@${ECHO} ""

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.post.mk>
