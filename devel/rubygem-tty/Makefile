# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tty
PORTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Toolbox for developing beautiful CLI clients

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-bundler>=1.16:sysutils/rubygem-bundler \
		rubygem-equatable>=0.5<1:devel/rubygem-equatable \
		rubygem-pastel>=0.7.2<0.8:devel/rubygem-pastel \
		rubygem-thor>=0.20.0<0.21:devel/rubygem-thor \
		rubygem-tty-box>=0.4.1<1:devel/rubygem-tty-box \
		rubygem-tty-color>=0.5<1:devel/rubygem-tty-color \
		rubygem-tty-command>=0.9.0<1:devel/rubygem-tty-command \
		rubygem-tty-config>=0.3.2<0.4:devel/rubygem-tty-config \
		rubygem-tty-cursor>=0.7<1:devel/rubygem-tty-cursor \
		rubygem-tty-editor>=0.5<1:devel/rubygem-tty-editor \
		rubygem-tty-file>=0.8.0<0.9:devel/rubygem-tty-file \
		rubygem-tty-font>=0.4.0<0.5:devel/rubygem-tty-font \
		rubygem-tty-logger>=0.2.0<1:devel/rubygem-tty-logger \
		rubygem-tty-markdown>=0.6.0<0.7:devel/rubygem-tty-markdown \
		rubygem-tty-pager>=0.12<1:devel/rubygem-tty-pager \
		rubygem-tty-pie>=0.3.0<0.4:devel/rubygem-tty-pie \
		rubygem-tty-platform>=0.2<1:devel/rubygem-tty-platform \
		rubygem-tty-progressbar>=0.17<1:devel/rubygem-tty-progressbar \
		rubygem-tty-prompt>=0.19<1:devel/rubygem-tty-prompt \
		rubygem-tty-screen>=0.7<1:devel/rubygem-tty-screen \
		rubygem-tty-spinner>=0.9<1:devel/rubygem-tty-spinner \
		rubygem-tty-table>=0.11.0<0.12:devel/rubygem-tty-table \
		rubygem-tty-tree>=0.3<1:devel/rubygem-tty-tree \
		rubygem-tty-which>=0.4<1:devel/rubygem-tty-which

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/teletype

.include <bsd.port.mk>
