/*
 *  Copyright (c) 2009-2010 Mike Massonnet <mmassonnet@xfce.org>
 *  Copyright (c) 2009-2010 Vincent Legout <vincent@xfce.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

[CCode (cprefix="", lower_case_prefix="", cheader_filename="config.h")]
namespace Config {
	[CCode (cname = "GETTEXT_PACKAGE")]
	public const string GETTEXT_PACKAGE;
	[CCode (cname = "PACKAGE_LOCALE_DIR")]
	public const string PACKAGE_LOCALE_DIR;
	[CCode (cname = "PACKAGE_VERSION")]
	public const string PACKAGE_VERSION;
	[CCode (cname = "PACKAGE_STRING")]
	public const string PACKAGE_STRING;
	[CCode (cname = "PACKAGE_NAME")]
	public const string PACKAGE_NAME;
}
