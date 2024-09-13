/*******************************************************************************
 * Copyright (c) 2020 Red Hat Inc.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 * 
 * Contributors:
 *     Red Hat Inc. - initial version
 *******************************************************************************/
package org.eclipse.equinox.internal.security.linux;

public class SecretServiceFlags {
	public final static int SECRET_SERVICE_NONE = 0;
	public final static int SECRET_SERVICE_OPEN_SESSION = 1 << 1;
	public final static int SECRET_SERVICE_LOAD_COLLECTIONS = 1 << 2;
}
